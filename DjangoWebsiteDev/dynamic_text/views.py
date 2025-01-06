from django.shortcuts import render

# Create your views here.
from django.http import HttpResponse

def dynamic_text_view(request):
    return render(request, 'dynamic_text/dynamic_text.html')