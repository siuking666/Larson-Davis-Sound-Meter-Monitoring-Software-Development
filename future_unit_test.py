### For future unit test

# Test get_unique_filename Function

import unittest
import os

class TestFileFunctions(unittest.TestCase):
    def test_get_unique_filename(self):
        base_path = 'test.csv'
        # Create a test file
        with open(base_path, 'w') as f:
            f.write('test')

        unique_filename = get_unique_filename(base_path)
        self.assertNotEqual(unique_filename, base_path)  # Should not be the same
        self.assertTrue(unique_filename.startswith('test_v'))  # Should have version suffix
        os.remove(base_path)  # Clean up
        os.remove(unique_filename)  # Clean up

#------------------------------------------

# Test log_data Function:

class TestLogDataFunction(unittest.TestCase):
    def test_log_data(self):
        test_filename = 'test_log.csv'
        log_data('2022/12/19', '12:00:00', '2022/12/19', '12:00:00', '50', test_filename)
        with open(test_filename, 'r') as f:
            lines = f.readlines()
            self.assertEqual(len(lines), 2)  # Check header + data row
        os.remove(test_filename)  # Clean up

#------------------------------------------

# Test find_LD_meter_ports Function

from unittest.mock import patch

class TestFindPortsFunction(unittest.TestCase):
    @patch('psutil.process_iter')
    def test_find_LD_meter_ports(self, mock_process_iter):
        mock_process_iter.return_value = [
            {'pid': 1234, 'name': 'HttpLD.exe', 'cmdline': ['-p', '2565', 'USB']},
            {'pid': 5678, 'name': 'other_process', 'cmdline': []}
        ]
        find_LD_meter_ports()
        self.assertEqual(usb_port, '2565')  # Check if USB port was found

#------------------------------------------

# Test get_device_info Function:

import requests

class TestGetDeviceInfoFunction(unittest.TestCase):
    @patch('requests.get')
    def test_get_device_info_success(self, mock_get):
        mock_response = unittest.mock.Mock()
        mock_response.headers = {'Content-Type': 'application/json'}
        mock_response.json.return_value = {"Status": {"Device": "Meter1", "Serial Number": "12345"}}
        mock_get.return_value = mock_response
        
        success, device_name, device_serial = get_device_info(2565)
        self.assertTrue(success)
        self.assertEqual(device_name, "Meter1")
        self.assertEqual(device_serial, "12345")

    @patch('requests.get')
    def test_get_device_info_failure(self, mock_get):
        mock_get.side_effect = requests.exceptions.Timeout
        success, device_name, device_serial = get_device_info(2565)
        self.assertFalse(success)
        self.assertIsNone(device_name)
        self.assertIsNone(device_serial)

#------------------------------------------

# Test get_device_status Function:
# Similar to get_device_info, mock the requests.get to handle both success and failure cases.
