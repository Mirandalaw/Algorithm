<html>
    <head>
        <meta charset="UTF-8">
        <title>출력결과</title>
    </head>
    <body>
        <script>
           function solution(a,b,c){
               let answer="YES",max;
               let sum =a+b+c;
               if(a>b)max =a;
               else max = b;
               if(c>max)max=c;
               if((sum-max)<=max)answer="NO";
               return answer;
           }
           console.log(solution(6,7, 11));
           /*가장 큰 변의 길이가 짧은변의 합보다 작을경우에 삼각형 성립*/
        </script>
    </body>
</html>
