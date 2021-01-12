from django.db import models

# Create your models here.
"""
往类别 创建迁移文件  python manage.py makemigrations

根据迁移文件  写入到数据库： python manage.py migrate
"""


# 一个类对应一个表
class User(models.Model):
    username = models.CharField(max_length=32)  # varchar(32)
    password = models.CharField(max_length=32)  # varchar(32)