from django.db import models

# Create your models here.

class UserInfo(models.Model):
    email = models.CharField(verbose_name="邮箱",unique=True)
    # 建立一个用户token 作为一个用户的标记
    token = models.CharField(verbose_name="用户TOKEN",max_length=64,null=True,blank=True)
