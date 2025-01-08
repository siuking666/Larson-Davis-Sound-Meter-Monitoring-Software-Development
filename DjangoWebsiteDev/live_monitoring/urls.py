# live_monitoring/urls.py

from django.urls import path
from .views import live_monitoring_view, live_monitoring_ajax

urlpatterns = [
    path('', live_monitoring_view, name='live_monitoring'),  # Root URL for live monitoring
    path('ajax/', live_monitoring_ajax, name='live_monitoring_ajax'),  # AJAX endpoint
]