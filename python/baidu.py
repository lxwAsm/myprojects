from    selenium import webdriver
from selenium.webdriver.support.wait import WebDriverWait  
from selenium.webdriver.support import expected_conditions as EC  
from selenium.webdriver.common.by import By 
import  time,itertools
def     main():
        driver=webdriver.Firefox()
        driver.maximize_window()
        time.sleep(1)
        driver.get("https://www.baidu.com")
        WebDriverWait(driver,20,0.5).until(EC.presence_of_element_located((By.ID,'kw')))
        print(driver.execute_script("return document.title"))
        elem_login = driver.find_element_by_xpath("//div[@id='u1']/a[7]")
        elem_login.click()
        time.sleep(2)
        driver.switch_to_default_content()
        driver.find_element_by_id('TANGRAM__PSP_10__footerULoginBtn').click()
        time.sleep(0.5)
        driver.find_element_by_id('TANGRAM__PSP_10__userName').send_keys('yourname')
        driver.find_element_by_id('TANGRAM__PSP_10__password').send_keys('password')
        driver.find_element_by_id('TANGRAM__PSP_10__submit').click()
        
        input("enter to end")
        
        driver.close()
if      __name__=="__main__":
        main()
