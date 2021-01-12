import random

from django.core.exceptions import ValidationError
from django_redis import get_redis_connection
from auction.settings import send_email
from django.http import JsonResponse
from django.shortcuts import render
from rest_framework import serializers
from rest_framework.views import APIView
from rest_framework.response import Response


# Create your views here.
# main 接口
class register_by_email(APIView):
    def post(self,request,*args,**kwargs):
        print(request.data)
        return Response({"status":True})

# 检车字段是否为邮箱
def email_validator(value):
    import re
    if not re.match(r"^[A-Za-z0-9\u4e00-\u9fa5]+@[a-zA-Z0-9_-]+(\.[a-zA-Z0-9_-]+)+$", value):
        raise Response("邮箱格式错误")

# 判断邮箱格式是否正确
class MessageSerializer(serializers.Serializer):
    email = serializers.CharField(label="邮箱",validators=[email_validator,])

# 判断邮箱格式是否正确
class LoginSerializer(serializers.Serializer):
    email = serializers.CharField(label="邮箱",validators=[email_validator,])
    code = serializers.CharField(label="验证码")

    def validate_code(self,value):
        if len(value) != 4 or not value.isdecimal():
            raise ValidationError("验证码格式错误")

        email = self.initial_data.get("email")
        conn = get_redis_connection()
        code = conn.get(email)
        if not code:
            raise ValidationError("验证码不存在")

        if value != code.decode('utf-8'):
            raise ValidationError("验证码错误")
        return value

# 发送验证码类
class send_code_by_email(APIView):
    def get(self,request,*args,**kwargs):
        # 获取邮箱
        email = request.query_params.get('email')
        # 邮箱格式检验
        ser = MessageSerializer(data=request.query_params)
        if not ser.is_valid():
            return Response({'status': False, 'message': '邮箱格式错误'})

        # 生成四位随机验证码
        random_code = random.randint(1000,9999)
        # TODO/DOED 将验证码通过邮箱发送
        send_result = send_email(email,random_code)
        if not send_result:
            return Response({"status":False,"message":'短信发送失败'})

        # 把验证码+手机号保留起来（60s 过期）
        # django 中方便使用redis 的模块 django-redis
        conn = get_redis_connection()
        conn.set(email,random_code,ex=60)

        print(JsonResponse({"status": True, "message": '发送成功'}))
        return Response({"status": True, "message": '发送成功'})

# 通过验证码登录
class login_by_email(APIView):
    def post(self,request,*args,**kwargs):
        """
        1、校验邮箱是否合法
        2、校验验证码
            - 无验证码
            - 有验证码
                -
                - 正确
                    数据库

        """

        ser = LoginSerializer(data=request.data)

        # email = request.data.get('email')
        # code = request.data.get('code')
        #
        # conn = get_redis_connection()
        # conn.get(email)

        if not ser.is_valid():
            return Response({"status":False,"message":"验证码错误"})

        return Response({"status":True})





















