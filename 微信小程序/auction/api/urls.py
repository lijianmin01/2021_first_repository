
from django.conf.urls import url,include
from api import views

urlpatterns = [
    url(r'^login/',views.LoginView.as_view())
]
