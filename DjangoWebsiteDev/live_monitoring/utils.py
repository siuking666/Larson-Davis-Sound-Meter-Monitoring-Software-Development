# live_monitoring/utils.py

from django.db import connection

def get_last_monitoring(limit=10):
    with connection.cursor() as cursor:
        query = """
        SELECT * FROM LiveMonitoring 
        ORDER BY meter_date DESC, meter_time DESC
        LIMIT %s
        """
        cursor.execute(query, [limit])
        rows = cursor.fetchall()

    columns = [col[0] for col in cursor.description]
    monitoring = [dict(zip(columns, row)) for row in rows]

    return monitoring