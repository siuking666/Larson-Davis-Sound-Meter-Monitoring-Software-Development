# live_monitoring/urls.py

from django.urls import path
from .views import live_measurements_view, live_measurements_ajax

urlpatterns = [
    path('', live_measurements_view, name='live_measurements'),
    path('ajax/', live_measurements_ajax, name='live_measurements_ajax'),
]