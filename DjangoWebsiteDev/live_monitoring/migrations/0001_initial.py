# Generated by Django 5.1.4 on 2025-01-06 08:51

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = []

    operations = [
        migrations.CreateModel(
            name="LiveMeasurements",
            fields=[
                (
                    "id",
                    models.BigAutoField(
                        auto_created=True,
                        primary_key=True,
                        serialize=False,
                        verbose_name="ID",
                    ),
                ),
                ("pc_date", models.TextField(blank=True, null=True)),
                ("pc_time", models.TextField(blank=True, null=True)),
                ("meter_date", models.TextField()),
                ("meter_time", models.TextField()),
                ("LAeq", models.FloatField()),
                ("response_time", models.FloatField()),
            ],
            options={
                "db_table": "LiveMeasurements",
                "managed": False,
            },
        ),
    ]
