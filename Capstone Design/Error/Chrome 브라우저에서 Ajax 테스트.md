# Chrome 브라우저에서 Ajax 테스트

Error Image
--------------
<div>
<img src = "https://user-images.githubusercontent.com/42960479/79352939-67f17500-7f75-11ea-899c-c81765cec97b.PNG">
</div>

--------------
이 에러 메시지는 크롬 브라우저에서 Ajax를 테스트 할 경우에 생긴다.
        
      <script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.0/jquery.min.js"></script>
      <script type="text/javascript">
 
 
위 소스 코드는 내가 사용한 코드이다. 나는 자바스크립트로 json파일을 만들 생각이었다. 파이썬으로도 json파일을 만들 수 있지만 Visual Studio Code를 사용해서 만드는 것이 수월하다고 생각했기 때문이다. json파일을 만들기 위한 준비를 모두 마치고 나서 크롬에서 실행을 시켜보았더니 위와 같은 에러가 하나 생겼다. 

* ### 첫 번째 해결방안 시도
구글링을 해보니 통상적으로 쓰이는 방법이 이 방법인 것 같아 사용해보았다. 

먼저, 열어놓은 크롬들을 모두 끈 후에 바탕화면에 구글 크롬 바로가기를 생성하여 대상 위치 맨 뒤에 
" --disable-web-security --user-data-dir"
을 입력하는 것이다.


   <center>
  <img height = "600px" width = "400px" src = "https://user-images.githubusercontent.com/42960479/79355569-ce2bc700-7f78-11ea-8a4d-f5eff22abee0.PNG">
</center>

 
 입력 한 뒤 확인을 누르고 바로가기 크롬을 눌러서 다시 실행시키면 된다,,,,,,
 
 라는데,
 나는 이걸로 해결이 되지 않았다. 
****
그런데 생각해보니까 나는 비록 자바스크립트로 json파일을 만들었지만, 이미 json파일을 생성했고, 그 생성된 json파일을 d3 라이브러리에 파싱하는 것 뿐인데 왜 이 에러가 나는 걸까. json 파일의 형식을 잘못 넣었나

****
해결법
------------------
2020-04
방법을 찾았다.
cmd 창에 <h3>' https-server [실행하고자하는 파일이있는 디렉토리] '</h3>를 엔터치면 서버 주소가 나오는데 그 중 하나를 복사해 주소창에 복붙하여 거기서 실행시키면 된다. 한마디로 직접 파일을 서버에 올리는 방식.
