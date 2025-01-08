# live_monitoring/models.py

from django.db import models

class LiveMonitoring(models.Model):
    pc_date = models.TextField()  # Use TextField for variable-length strings
    pc_time = models.TextField()  # Use TextField for variable-length strings
    unix_time = models.BigIntegerField(primary_key=True)  # Use BigIntegerField for larger values
    meter_date = models.TextField()  # Use TextField for variable-length strings
    meter_time = models.TextField()  # Use TextField for variable-length strings
    LAeq = models.FloatField()
    response_time = models.FloatField()

    class Meta:
        db_table = 'LiveMonitoring'
        managed = False  # Prevent Django from managing this table