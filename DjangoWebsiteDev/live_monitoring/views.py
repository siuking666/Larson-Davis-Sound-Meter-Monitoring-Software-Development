# live_monitoring/views.py

from django.http import JsonResponse
from django.shortcuts import render
from .models import LiveMonitoring  # Import the LiveMonitoring model

def live_measurements_view(request):
    # Get the last 10 entries from the LiveMonitoring model
    measurements = LiveMonitoring.objects.all().order_by('-unix_time')[:10]
    return render(request, 'live_monitoring.html', {'measurements': measurements})

def live_measurements_ajax(request):
    # Get the last 10 entries from the LiveMonitoring model
    measurements = LiveMonitoring.objects.all().order_by('-unix_time')[:10]
    
    # Convert the queryset to a list of dictionaries for JSON response
    measurements_list = list(measurements.values())  # Use values() to create a list of dicts
    return JsonResponse(measurements_list, safe=False)