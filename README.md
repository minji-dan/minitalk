# minitalk
: (42cursus - minitalk) 유닉스 신호를 주고 받는 작은 데이터 교환 프로그램    

## 구현사항
```
-SIGUSR1이 SERVER의 PID로 문자열을 입력  
-SIGUSR2는 CLIENT로 주어진 문자열을 출력  
```

## Install
```
$ make
```

## Running 
- server terminal

```
$ ./server
```
- client terminal
```
$ ./client [server_id] [문자열]
```


## Feedback
```
- signal vs. sigaction
- unicode가 작동하는 이유 
- SA_FLAG 사용 이유
```
