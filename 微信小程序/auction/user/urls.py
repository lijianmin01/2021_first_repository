from django.conf.urls import url,include
from user import views

urlpatterns = [
    url(r'^register_by_email/',views.register_by_email.as_view()),
    url(r'^send_code_by_email/',views.send_code_by_email.as_view()),
    url(r'^login_by_email/',views.login_by_email.as_view()),
]