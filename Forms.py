from selenium import webdriver
from selenium.webdriver.common.by import By
import time

class GoogleFormAutomation:
    def setUp(self):
        self.driver = webdriver.Chrome()

    def fill_form(self):
        self.driver.get("https://forms.gle/mSV8WEUWiBEFA4J88")
        time.sleep(2)

        # Fill the Name field
        name = "name"
        name_input = self.driver.find_element(By.CLASS_NAME, "whsOnd")
        name_input.send_keys(name)
        time.sleep(2)
        
        # Fill the USN field
        usn = "4SF21IS000"
        usn_input = self.driver.find_elements(By.CLASS_NAME, "whsOnd")[1]  # Second input field
        usn_input.send_keys(usn)
        time.sleep(2)
        
        # Submit the form
        submit = self.driver.find_element(By.CLASS_NAME, "NPEfkd")
        submit.click()
        time.sleep(2)

    def tearDown(self):
        self.driver.quit()

if __name__ == "__main__":
    automation = GoogleFormAutomation()
    automation.setUp()
    automation.fill_form()
    automation.tearDown()
