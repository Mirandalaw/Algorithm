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
        </script>
    </body>
</html>
