# Comjipsa-컴집사
---
## 컴집사란?
사용자들의 좋지 않은 컴퓨터 사용 습관을 고치기 위한 보안 솔루션 프로그램입니다.   

## 원리
사용자가 인터넷을 들어갈 때 URL을 분석하여 블랙리스트 DB에 포함되어 있는지 확인합니다.   
만약 있을 경우, 웹사이트 접근 권한을 거부하고 로그를 남깁니다. (날짜, 시간과 함께)   

## 개발 동기
인터넷의 발전과 함께 그에 따른 사이버 범죄도 심각합니다.   
2017년 5월 랜섬웨어 국내 대량 유포, 급증하는 몸캠 피싱, 범죄 뿐 아니라 심지어는 보안적인 문제도 일어나고 있습니다.   
몇몇 바이러스는 웹페이지 자체에 심어 접속하자마자 내 컴퓨터가 좀비 PC가 되기도 하고, 웹캠 녹화와 마이크 녹음 권한도 얻습니다.    
따라서 이런 일을 사전에 예방하고자 PC 최적화와 보안을 지킬 수 있는 통합 솔루션 프로그램을 만들게 되었습니다.   

## 개발 과정
처음의 걱정과는 달리 과정은 꽤 수월했습니다.     
원래의 계획은 인터넷 브라우저에서 현재 접근하려는 URL 을 파싱하려고 했으나 JS 를 쓰면 또 다른 부분에 문제가 생겨   
조금 다른 방식으로 C언어로 구현을 했습니다.   
C언어 API 와 도스 언어의 명령어를 섞어서 만들었습니다.

---

## 프로그램 원리
![1.png](https://raw.githubusercontent.com/D3vle0/comjipsa/master/photo/1.PNG)

접속하고자 하는 url 을 입력하면 해당 주소로 인터넷에 접속 할 수 있습니다.   
만약 현재 블랙리스트로 등록된
```
naver.com
```
또는
```
google.com
```
을 입력하게 되면   
![2.png](https://raw.githubusercontent.com/D3vle0/comjipsa/master/photo/2.PNG)

위와 같은 MessageBox가 나옵니다.   
예를 눌렀을 경우 로그파일에 "Unsafe webpage accessed" 라고 기록되고, 아니요를 눌렀을 경우 로그파일에 "Webpage Blocked" 라고 기록됩니다.   

![3.png](https://raw.githubusercontent.com/D3vle0/comjipsa/master/photo/3.PNG)

comjipsa.exe 파일과 함께 실행되는 timer.exe 는 1시간에 1번씩 dns 캐시를 플러쉬해줍니다.   
인터넷 속도가 약간 향상되는 효과를 보실 수 있습니다.   

## 지능적인 블랙리스트 알고리즘
기존에 저희가 생각한 방식인 string.h 의 strcmp로 블랙리스트를 판별하는 것은 매우 치명적인 취약점이 있습니다.   
예를 들어
```
naver.com
```
이 블랙리스트에 등록되었다면, strcmp 함수 특성상 사용자가 접속하고자하는 url 과 완벽히 일치해야합니다. 그럼
```
https://naver.com
```
또는
```
http://naver.com
```
등의 방법으로 우회가 가능합니다.   

위의 경우를 다 블랙리스트에 등록했다면 어떻게 될까요?   
중심이 되는 도메인은 접근 불가능하지만 subdomain 은 접근 가능합니다.   
한마디로 naver.com 은 차단되지만 search.naver.com 은 차단되지 않습니다.   
    
그럼 google.com 의 예시를 봅시다.   
만약에 test 라는 내용을 검색하고 싶으면 google.com 뒤에    
```
/search?q=test&oq=test
```
이것을 넣으면 됩니다.   
URL Query 를 이용해도 우회가 가능하기 때문에 strcmp 함수는 안전하지 않습니다.   
따라서 strstr 함수를 사용했는데요, 접속하고자 하는 url 에 naver.com 이 포함되어 있으면 모두 차단됩니다.   
```
kin.naver.com
```
```
newsstand.naver.com
```
```
blog.naver.com
```
모두 차단할 수 있습니다.   
구글의 경우 google.co.uk, co.jp, co.kr 등 여러 도메인이 있기 때문에 'google.' 라는 문자열이 포함되어 있으면 차단되게 했습니다.   

## 더 나은 사용자 경험을 위해...
이 세상의 모든 유해 웹페이지를 사람이 일일이 등록할 수는 없습니다.
>myreport.kro.kr
에 가셔서 사용자분들이 유해 웹페이지를 등록시킬 수 있습니다.
