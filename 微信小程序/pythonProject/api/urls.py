from django.conf.urls import url,include
from django.contrib import admin
from django.urls import path
from api import views

urlpatterns = [
    url(r'^login',views.LoginView.as_view())
]
