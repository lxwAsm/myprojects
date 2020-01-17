#!/usr/bin/python
# -*- coding: UTF-8 -*-
import requests,json
import smtplib
from email.mime.text import MIMEText
from email.utils import formataddr

my_sender = '3456319404@qq.com'  # 发件人邮箱账号
my_pass =   'your_password'# 发件人邮箱密码
my_user = '3456319404@qq.com' # 收件人邮箱账号

def color(text,cor):
    return "<font color='%s'>%s</font>"%(cor,text)

def send_mail(to,title,content):
    ret = True
    try:
        msg = MIMEText(content, 'html', 'utf-8')
        msg['From'] = formataddr(["python自动化", my_sender])  # 括号里的对应发件人邮箱昵称、发件人邮箱账号
        msg['To'] = formataddr(["FK", my_user])  # 括号里的对应收件人邮箱昵称、收件人邮箱账号
        msg['Subject'] = title #标题
        server = smtplib.SMTP_SSL("smtp.qq.com", 465)  # 发件人邮箱中的SMTP服务器，端口是25
        server.login(my_sender, my_pass)  # 括号中对应的是发件人邮箱账号、邮箱密码
        server.sendmail(my_sender,to, msg.as_string())  # 括号中对应的是发件人邮箱账号、收件人邮箱账号、发送邮件
        server.quit()
    except Exception:
        ret = False
    return ret
    #'yvctxggzyrtechhf'
def day(data):
    ret=""
    apidata=(data)["data"]["forecast_24h"]
    i = (apidata['1'])
    ret+=(i["time"] + ':' + '白天天气为:' + i['day_weather'] + "," + "最高气温为" + color(i["max_degree"]+"℃","red") + "，最低气温为" + color(i["min_degree"]+'℃',"green") + ","
          + i["day_wind_power"] + "级" + i["day_wind_direction"] + '；' + '晚上天气为' + i[
        'night_weather'] + "," + i["day_wind_power"] + "级" + i["day_wind_direction"] + "。")
    tipsdata = data["data"]["tips"]["observe"]
    ret+="<br>"+color(tipsdata["0"]+"  "+tipsdata["1"],"green")+"<br>"+"-"*30+"<br>"
    indexdata=(data)["data"]["index"]
    update_time=[]
    for i in indexdata:
        update_time.append((i))
    for n in update_time:
        if n == "time":
            pass
        else:
            i = (indexdata[n])
            if i['name']=="雨伞":
                ret+=color(i["name"]+":"+i["info"]+";"+'<br>','red')#+i["detail"]
            else:
                ret += i["name"] + ":" + i["info"] + ";" + '<br>'
    return ret

def seven_day(data):
    ret=""
    apidata=(data)["data"]["forecast_24h"]
    update_time=[]
    for i in apidata:
        update_time.append(int(i))
    update_time.sort()
    for n in update_time:
        i=(apidata[str(n)])
        ret+=(i["time"]+':'+'白天天气为'+i['day_weather']+","+"最高气温为"+color(i[ "max_degree"]+'℃','red')+"，最低气温为"+color(i[ "min_degree"]+"℃,",'green')+i["day_wind_power"]+"级"+i["day_wind_direction"]+'；'+'晚上天气为'+i['night_weather']+","+i["day_wind_power"]+"级"+i["day_wind_direction"]+"。<br>" )
    return ret

def get_weather():
    url = "https://wis.qq.com/weather/common"
    querystring = {"source":"xw","weather_type":"forecast_1h|forecast_24h|index|alarm|limit|tips","province":"重庆","city":"重庆"}
    headers = {}
    response = requests.request("GET", url, headers=headers, params=querystring)
    return json.loads(response.text)

def wether_info():
    data = get_weather()
    s = day(data) + "<br>" + seven_day(data)
    return s

if send_mail(["3456319404@qq.com"],"天气",wether_info()):
    print("ok")
else:
    print("error")