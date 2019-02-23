#!/usr/bin/env python
# -*- coding: utf-8 -*-
from    selenium import webdriver
from selenium.webdriver.support.wait import WebDriverWait  
from selenium.webdriver.support import expected_conditions as EC  
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver import FirefoxOptions
import  time,itertools,random
def     main():
        opts = FirefoxOptions()
        #opts.add_argument("--headless")dont show the page
        option_profile = webdriver.FirefoxProfile() 
        option_profile.set_preference("plugin.state.flash",2) 
        driver = webdriver.Firefox(firefox_profile=option_profile,options=opts)
        driver.maximize_window()
        time.sleep(1)
        driver.get("https://www.huya.com")
        WebDriverWait(driver,20,0.5).until(EC.presence_of_element_located((By.CLASS_NAME,'hy-nav-title.J_hdLg')))
        driver.find_element_by_class_name('hy-nav-title.J_hdLg').click()
        #WebDriverWait(driver,20,0.5).until(EC.presence_of_element_located((By.ID,'nav-login')))
        #https://www.huya.com/685233
        wandMsg=[u'有人一起开黑的吗',u'鲁班的攻击距离长,更适合远程消耗敌人',u'主播那么厉害']
        WebDriverWait(driver, 2000, 0.5).until(EC.presence_of_element_located((By.ID, 'pub_msg_input')))
        sendBtn = driver.find_element_by_id('msg_send_bt')
        msg = driver.find_element_by_id('pub_msg_input')
        if msg!=None and sendBtn!=None:
                print 'msg btn found..'
                js = 'document.getElementById("pub_msg_input").value="%s";'
                text="[害羞]"
                while True:
                        driver.execute_script(js%text)
                        msg.send_keys(wandMsg[random.randint(0,len(wandMsg))%len(wandMsg)])
                        time.sleep(random.randint(5,10))
                        msg.send_keys(Keys.ENTER)
        raw_input('enter to end')
        driver.close()
if      __name__=="__main__":
        main()
