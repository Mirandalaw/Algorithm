<html>
  <head>
    <meta charset="UTF-8" />
    <title>출력결과</title>
  </head>
  <body>
    <script>
      function solution(n){
        let answer = 0;
        for (let i=1;i<=n;++i){
          answer+=i;
        }
        return answer;
      }
      console.log(solution(6));
      </script>
  </body>
</html>
