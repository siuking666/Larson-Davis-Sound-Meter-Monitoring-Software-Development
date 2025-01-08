# live_monitoring/models.py

from django.db import models

class LiveMonitoring(models.Model):
    pc_date = models.TextField()  # Consider using DateField if it's a date
    pc_time = models.TextField()  # Consider using TimeField if it's a time
    unix_time = models.BigIntegerField(primary_key=True)  # Good choice for larger values
    meter_date = models.TextField()  # Consider using DateField if it's a date
    meter_time = models.TextField()  # Consider using TimeField if it's a time
    LAeq = models.FloatField()
    response_time = models.FloatField()

    class Meta:
        db_table = 'LiveMonitoring'
        managed = False  # This is fine if the table is managed outside of Django