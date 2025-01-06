
from django.urls import path
from .views import dynamic_text_view

urlpatterns = [
    path('', dynamic_text_view, name='dynamic_text'),
]