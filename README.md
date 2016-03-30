# mybaseball-client
mybaseball game client

# 설명
야구 시뮬레이션 게임입니다. 

# 핵심 재미
야구 선수를 이용해 승리할 수 있는 카드 조합을 찾아내는 재미.

# 세부 내용
리스트에 있는 선수들 중에 일부를 뽑아서, 경기를 시작한다.
야구경기의 처음부터 끝까지 한바퀴 시뮬레이션을 시행함. 

# 일정
## 1주차  
### 게임씬  
기본 레이아웃 , 기본 버튼 및 기본 씬 전환 제작  
  
### 로직  
선수 객체 설정 및 투수-타자 승부 로직 만들기  (승리-안타, 패배-삼진)
승패에 따른 아웃카운트 변화 구현  
임의로 생성한 선수 객체를 통해서 테스트.  

  
## 2주차
### 게임씬
인플레이 씬 디자인. 결과 텍스트로 출력  
상황에 따른 주자 이동변화 구현  
주자 및 상황 스프라이트로 표현  
  
### 로직
투수- 타자 결과를 이용해 최종 결과 재가공하기  ( 승리 - 안타, 홈런, 1루타, 2루타, 3루타, 등등)
결과에 따른 주루 판단 구현  
   
## 3주차  
### 대기실 씬 구현
선수 풀에서 선택해서 팀 구성하기  
승/패 UI Layer 구현  
파일을 통해 유저 기록 저장 구현  
  
### 로직  
결과 가공시 평균적인 통계에 의존하도록 가중치 변경
팀에 따른 최종 결과 재가공 구현  
  
## 4주차 - 데이터 수집  
### 실제 데이터 크롤링  
  
## 5주차
### 서버측을 이용한 DB 활용 구현  
유저 로그인 및 정보 DB 통해 저장/로드
각 선수별 DB 활용하여 실제 데이터에 반영
  
  
