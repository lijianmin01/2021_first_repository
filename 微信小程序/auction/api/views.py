from django.shortcuts import render
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import serializers
from rest_framework.exceptions import ValidationError

# Create your views here.

def phone_validator(value):
    import re
    if not re.match(r"^(1[3|4|5|6|7|8|9])\d(9)$", value):
        return Response("手机号格式错误")

class MessageSerializer(serializers.Serializer):
    phone = serializers.CharField(label="手机号",validators=[phone_validator,])

class MessageView(APIView):
    def get(self,request,*args,**kwargs):
        # 获取手机号
        phone = request.query_params.get('phone')
        # 手机格式校验
        ser = MessageSerializer(data=request.query_params)
        if not ser.is_valid():
            return Response({'status':False,'message':'手机格式错误'})

        # phone = ser.validated_data.get('phone')
        # 生成随机验证码
        import random
        random_code = random.randint(1000,9999)
        # 验证码发送到手机上
        # TODO tencent.send_message(phone,random_code)
        """
            1、注册腾讯云，开通腾讯云短信
            2、创建应用
                SDK AppId =
            3、申请签名
                个人：公众号
            4、申请模板
            5、申请腾讯云
                appid 
        """

        # 把验证码+手机号保留起来（30s 过期）
        #   5.1 搭建redis 服务器
        """
            import redis
            pool = redis.ConnectionPool(host='',port)
            conn = redis.Redis(connection_pool=pool)
            conn.set(phone,random_code,ex=30)
        """
        #   5.2 django 中方便使用redis 的模块 django-redis
        #       配置   在setting
        from django_redis import get_redis_connection
        conn = get_redis_connection()
        conn.set(phone,random_code,ex=30)

        return Response({"status":True,"message":'发送成功'})
        #   conn.set("15111111111",'1678',ex=30)
        #   code = conn.get("15111111111")
        print(phone)
        return Response({"status":True})

class LoginView(APIView):
    def post(self,request,*args,**kwargs):
        print(request.data)
        return Response({"status":True})


# 发送邮件
def send_email(email_id,code):
    from django.core.mail import send_mail
    email_title = '邮件标题'
    email_body = '邮件内容'
    email = '1796887546@qq.com'  # 对方的邮箱
    send_status = send_mail(email_title, email_body, "alkefu@sina.com", [email])

    if send_status:
        print("成功")
# 发送成功


