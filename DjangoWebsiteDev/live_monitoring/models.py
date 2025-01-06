# live_monitoring/models.py

from django.db import models

class LiveMeasurements(models.Model):
    pc_date = models.TextField(blank=True, null=True)
    pc_time = models.TextField(blank=True, null=True)
    meter_date = models.TextField()  # NOT NULL in the database
    meter_time = models.TextField()  # NOT NULL in the database
    LAeq = models.FloatField()  # NOT NULL in the database
    response_time = models.FloatField()  # NOT NULL in the database

    class Meta:
        db_table = 'LiveMeasurements'
        unique_together = (('meter_date', 'meter_time'),)  # Composite key
        managed = False  # Prevent Django from managing this table