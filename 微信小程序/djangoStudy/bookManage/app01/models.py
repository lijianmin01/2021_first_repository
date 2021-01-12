from django.db import models

# Create your models here.

# 出版社类
class Publisher(models.Model):
    name = models.CharField(max_length=32)

# 书籍表
class book(models.Model):
    name = models.CharField(max_length=32)
    publisher_id = models.ForeignKey(Publisher,on_delete=models.CASCADE) # 默认是级联删除
    """
    on_delete 
        models.CASCADE  级联删除
        models.PROTECT  保护
        model.SET(v)    删除后设置为某个值
        model.SETDEFAULT    删除后设置为默认值
        model.SET(v)    删除后设置为某个值
        model.SET_NULL    删除后设置为空
    """





