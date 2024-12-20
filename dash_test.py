import dash
from dash import html, dcc
from dash.dependencies import Input, Output

app = dash.Dash(__name__)

app.layout = html.Div([
    dcc.Dropdown(
        id='dropdown',
        options=[
            {'label': 'Option 1', 'value': '1'},
            {'label': 'Option 2', 'value': '2'},
        ],
        value='1'
    ),
    html.Div(id='output')
])

@app.callback(
    Output('output', 'children'),
    Input('dropdown', 'value')
)
def update_output(value):
    return f'You selected: {value}'

if __name__ == '__main__':
    app.run_server(debug=True)