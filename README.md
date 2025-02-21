Repo for the development of a Real-Time Noise Monitoring Software, intended to be used with Larson Davis sound meters. This project is unfortunately on hold at the moment.
- Most of the components are written in Python.
- The SQL database component uses SQLite for now, for local testing. Switching to MySQL or other cloud server is planned.
- The dynamic live display and query website is written with Python Django, HTML, CSS and Javascript.

The software builds on top of the LD official G4 Utility software, specifically, its HTTP communication protocol. 
The entire project is separated into a few components, each with its own Python script. Eventual total integration is planned.
- The main code - real-time monitoring; auto detects and connects with a sound meter, polls the sound meter every second, logs data locally, uploads data to a SQL database.
- The auxiliary code - exported data processing; works on the CSV data files exported every minute through G4 Utility, extracts only desired data, and uploads data to a SQL database.
- The SQLite codes - creates, exports, uploads data (before integrations) to the SQLite databases. Also contains a stress test code for testing purposes.
- Django website (in progress) - a website being built to dynamically display the sound level in real time using Javascript. A query and plot functionality on past data is also planned.

For documentation of each pieces of code/component, see the individual Readme.md files:
- Readme_create_SQLite_database.md
- Readme_export_SQLite_database.md
- Readme_exported-data-processing.md
- Readme_HTML-website-dev.md
- Readme_real-time-monitoring-with-SQL.md
- Readme_upload-processed-exported-data-to-SQL.md
