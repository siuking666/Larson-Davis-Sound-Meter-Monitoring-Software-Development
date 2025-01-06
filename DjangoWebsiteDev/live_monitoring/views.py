# live_monitoring/views.py

from django.http import JsonResponse
from django.shortcuts import render
from .utils import get_last_measurements

def live_measurements_view(request):
    measurements = get_last_measurements()  # Get the last 10 entries
    return render(request, 'live_monitoring.html', {'measurements': measurements})

def live_measurements_ajax(request):
    measurements = get_last_measurements()  # Get the last 10 entries
    return JsonResponse(measurements, safe=False)