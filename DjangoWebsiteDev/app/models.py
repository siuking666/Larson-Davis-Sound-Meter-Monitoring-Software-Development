"""
Definition of models.
"""

from django.db import models

# Create your models here.

class LiveMeasurements(models.Model):
    pc_date = models.TextField(blank=True, null=True)  # Allows NULL values based on your table definition
    pc_time = models.TextField(blank=True, null=True)  # Allows NULL values based on your table definition
    meter_date = models.TextField()  # NOT NULL in the database
    meter_time = models.TextField()  # NOT NULL in the database
    LAeq = models.FloatField()  # NOT NULL in the database
    response_time = models.FloatField()  # NOT NULL in the database

    class Meta:
        db_table = 'LiveMeasurements'  # Specify the existing table name
        managed = False  # Prevent Django from trying to create or modify this table
        unique_together = (('meter_date', 'meter_time'),)  # Define the composite primary key