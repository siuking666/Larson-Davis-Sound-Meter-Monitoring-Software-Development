## Notes for HTML website development:

# Project Directory vs. Apps
# Project Directory (myproject/):
- This directory contains **global** settings and configurations for your entire Django project.
- settings.py: Contains configuration settings for the entire project, such as database settings, installed apps, middleware, and more.
- urls.py: Defines the URL routing for the entire project. It maps URLs to views, which can come from any app within the project.
- wsgi.py: Used for deploying the project on a web server.

# Apps:
- Each app is a separate component of your project that encapsulates a specific functionality or feature. Apps can be reused across different projects.
- Each app typically has its own directory containing files like:
	- models.py: Defines the application's data models.
	- views.py: Contains the views that handle requests and responses.
	- urls.py (optional): Can define URL patterns specific to that app.
	- admin.py: Configures the app・s models for the Django admin interface.
	- migrations/: Contains database migration files for the app.


<!-- id attribute as a unique label for an HTML element. This label allows you to easily select and manipulate that specific element using JavaScript or jQuery -->
    <p class="lead" id="dynamic-text">Loading...</p> <!-- Dynamic text integrated here -->


- If the function is embedded in the main code, UpdateDynamicText() will execute immediately, and the return value of that function will be passed to setInterval.
- The function will only run once right away, not repeatedly at the specified interval, as setInterval expects a function reference, not the result of a function call.
<script>setInterval(updateDynamicText, 1000);</script> // Update the dynamic text every second

- Extending the Layout: By using {% extends "app/layout.html" %}, you ensure that your new page uses the same header, footer, and overall layout as the other pages.
- Dynamic Content Block: The {% block content %}...{% endblock %} section allows you to insert content specific to this page while keeping the overall layout intact.
- Bootstrap Classes: If you're using Bootstrap or similar CSS frameworks, you can add relevant classes (like table, jumbotron, etc.) to style the table and other elements.


# if i understand correctly, we use models.py to query the SQL database, pass the data onto views.py for rendering, then urls.py for mapping the end point?
Yes, you・ve understood the flow correctly! Here・s a summary of how each component interacts in a Django application:

1. models.py
Purpose: Defines the data structure of your application.
Functionality:
Represents tables in your SQL database as Python classes.
Allows you to query, create, update, and delete records in the database using Django・s ORM (Object-Relational Mapping).
In your case, the LiveMeasurements model is defined to reflect the existing table structure.
2. views.py
Purpose: Contains the logic for processing requests and returning responses.
Functionality:
Queries the database using the models defined in models.py.
Processes any business logic needed for the application.
Prepares context data (like the live measurements) to be passed to templates for rendering.
In your example, live_measurements_view fetches data from the LiveMeasurements model and passes it to the template.
3. urls.py
Purpose: Maps URL patterns to specific view functions.
Functionality:
Defines the routes your application will respond to.
Connects incoming requests to the appropriate views.
In your setup, the URL configuration in live_monitoring/urls.py maps the base URL /live-monitoring/ to the live_measurements_view.

# The Flow of Data
Request: A user navigates to a specific URL (e.g., /live-monitoring/).
URL Routing: Django checks the URL patterns in urls.py to find a match and calls the associated view function.
Data Query: The view function in views.py queries the database using the model defined in models.py.
Rendering: The view prepares the context and renders the appropriate HTML template, passing the data to be displayed.
Response: The rendered HTML is sent back to the user・s browser.