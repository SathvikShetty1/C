from selenium import webdriver
from selenium.webdriver.common.by import By
import time

class GoogleFormAutomation:
    def setUp(self):
        self.driver = webdriver.Chrome()

    def fill_form(self):
        # Open the Google Form
        self.driver.get("https://forms.gle/mSV8WEUWiBEFA4J88")
        time.sleep(2)
        
        # Fill the 'Name' field
        name = "name"
        name_input = self.driver.find_element(By.XPATH, '//input[@aria-labelledby="i1 i4"]')
        name_input.send_keys(name)
        time.sleep(2)
        
        # Fill the 'USN' field
        usn = "4SF21IS000"
        age_input = self.driver.find_element(By.XPATH, '//input[@aria-labelledby="i6 i9"]')
        age_input.send_keys(usn)
        time.sleep(2)
        
        # Submit the form
        submit = self.driver.find_element(By.XPATH, '//*[@id="mG61Hd"]/div[2]/div/div[3]/div[1]/div[1]/div/span/span')
        submit.click()
        time.sleep(2)

    def tearDown(self):
        self.driver.quit()

if __name__ == "__main__":
    automation = GoogleFormAutomation()
    automation.setUp()
    automation.fill_form()
    automation.tearDown()
