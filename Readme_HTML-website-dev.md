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
	- admin.py: Configures the app¡¦s models for the Django admin interface.
	- migrations/: Contains database migration files for the app.


<!-- id attribute as a unique label for an HTML element. This label allows you to easily select and manipulate that specific element using JavaScript or jQuery -->
    <p class="lead" id="dynamic-text">Loading...</p> <!-- Dynamic text integrated here -->


- If the function is embedded in the main code, UpdateDynamicText() will execute immediately, and the return value of that function will be passed to setInterval.
- The function will only run once right away, not repeatedly at the specified interval, as setInterval expects a function reference, not the result of a function call.
<script>setInterval(updateDynamicText, 1000);</script> // Update the dynamic text every second