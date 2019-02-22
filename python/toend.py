from    selenium import webdriver
from selenium.webdriver.support.wait import WebDriverWait  
from selenium.webdriver.support import expected_conditions as EC  
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.action_chains import ActionChains
import  time,itertools
def     main():
        driver=webdriver.Firefox()
        driver.maximize_window()
        time.sleep(1)
        driver.get("https://www.baidu.com")
        WebDriverWait(driver,20,0.5).until(EC.presence_of_element_located((By.ID,'kw')))
        print(driver.execute_script("return document.title"))
        driver.set_window_size(500,500)
        driver.find_element_by_id('kw').send_keys("selenium")
        driver.find_element_by_id('su').click()
        WebDriverWait(driver, 20, 0.5).until(EC.presence_of_element_located((By.ID, 'foot')))
        foot = driver.find_element_by_id('foot')
        driver.execute_script("arguments[0].scrollIntoView();", foot) #滑动到底部，不同的页面定位到底部的元素也不一样
        input("enter to end")
        driver.close()
if      __name__=="__main__":
        main()
