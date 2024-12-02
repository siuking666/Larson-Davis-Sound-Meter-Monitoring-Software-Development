import psutil

def find_http_ld_port():
    found_http_ld = False
    for proc in psutil.process_iter(['pid', 'name', 'cmdline']):
        try:
            print(f"Process Name: {proc.info['name']}, Command Line: {proc.info['cmdline']}")
            if proc.info['name'] == 'HttpLD.exe':
                found_http_ld = True
                cmdline = proc.info['cmdline']
                if cmdline and len(cmdline) > 1:
                    for arg in cmdline:
                        if '-port' in arg:
                            parts = arg.split(',')
                            for part in parts:
                                if '-port' in part:
                                    port = part.split(' ')[-1]
                                    return port
        except (psutil.NoSuchProcess, psutil.AccessDenied):
            continue  # Skip processes that are no longer available or inaccessible

    return None if not found_http_ld else "HttpLD.exe is running but port not found."

port_number = find_http_ld_port()
print(f"Current port number: {port_number}")

