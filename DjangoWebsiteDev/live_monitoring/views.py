# live_monitoring/views.py

from django.http import JsonResponse
from django.shortcuts import render
from .models import LiveMonitoring  # Import the LiveMonitoring model

def live_monitoring_view(request):
    # Get the last 10 entries in reverse chronological order
    last_entries = LiveMonitoring.objects.all().order_by('-unix_time')[:10]
    # Convert to a list and sort it chronologically
    monitoring = sorted(last_entries, key=lambda x: x.unix_time)
    return render(request, 'live_monitoring.html', {'monitoring': monitoring})

def live_monitoring_ajax(request):
    # Get the last 10 entries in reverse chronological order
    last_entries = LiveMonitoring.objects.all().order_by('-unix_time')[:10]
    # Convert to a list and sort it chronologically
    monitoring = sorted(last_entries, key=lambda x: x.unix_time)
    
    # Create a list of dictionaries for JSON response using actual fields
    monitoring_list = [{
        'pc_date': entry.pc_date,
        'pc_time': entry.pc_time,
        'unix_time': entry.unix_time,
        'meter_date': entry.meter_date,
        'meter_time': entry.meter_time,
        'LAeq': entry.LAeq,
        'response_time': entry.response_time
    } for entry in monitoring]
    
    return JsonResponse(monitoring_list, safe=False)