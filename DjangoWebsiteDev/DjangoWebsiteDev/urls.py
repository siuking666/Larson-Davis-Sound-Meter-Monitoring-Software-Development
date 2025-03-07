"""
Definition of urls for DjangoWebsiteDev.
"""

from datetime import datetime
from django.contrib import admin
from django.contrib.auth.views import LoginView, LogoutView
from main_website import forms, views
from django.urls import path, include


urlpatterns = [
    path('', views.home, name='home'),
    path('contact/', views.contact, name='contact'),
    path('about/', views.about, name='about'),
    path('login/',
         LoginView.as_view
         (
             template_name='main_website/login.html',
             authentication_form=forms.BootstrapAuthenticationForm,
             extra_context=
             {
                 'title': 'Log in',
                 'year' : datetime.now().year,
             }
         ),
         name='login'),
    path('logout/', LogoutView.as_view(next_page='/'), name='logout'),
    path('admin/', admin.site.urls),
    #path('dynamic_text/', include('dynamic_text.urls')),  # Add this line
    path('live-monitoring/', include('live_monitoring.urls')),  # Include the live_monitoring URLs
]
