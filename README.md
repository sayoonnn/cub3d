<pre>
               _      _____ ______ 
             | |    |____ ||  _  \
  ___  _   _ | |__      / /| | | |
 / __|| | | || '_ \     \ \| | | |
| (__ | |_| || |_) |.___/ /| |/ / 
 \___| \__,_||_.__/ \____/ |___/   
</pre>


![cub3D](https://github.com/user-attachments/assets/87a78bdb-c042-4b56-b5b2-904488da84df)

## 개요
[Wolfenstein 3D](https://en.wikipedia.org/wiki/Wolfenstein_3D)의 `레이 캐스팅`을 구현해보는 프로젝트로    

- 42 school의 [minilib-mlx](https://harm-smits.github.io/42docs/libs/minilibx.html) 라이브러리를 이용했습니다
- [Lay Casting](https://en.wikipedia.org/wiki/Ray_casting)을 이용하여 벽, 바탕, 천장을 그립니다


## 사용 방법

### 실행
- `cmake`가 필요합니다
```
sudo apt install cmake

make && ./cub3d {mapfile}
```

### 설정
- 실행 시 맵파일을 지정할 수 있습니다
  - 맵파일은 `.cub`로 끝나야 합니다
  - 맵파일은 다음과 같은 형식으로 이루어져 있습니다

```
NO ./textures/greystone.xpm
SO ./textures/mossy.xpm
WE ./textures/wood.xpm
EA ./textures/greystone.xpm

F 123,123,123
C 30,30,30

111111111111111111
100000000000000001
101000100001000001
100010000E01000001
100100000001000001
100000001111000001
100000000000000001
111111111111111111
```
  - `NO`, `SO`, `WE`, `EA`는 각각, 북, 남, 동, 서의 텍스쳐 설정입니다
  - 텍스쳐는 `.xpm` 형식만 가능합니다
  - F는 바닥, C는 천장의 색입니다
  - 가장 마지막 부분은 움직일 수 있는 공간으로
    - `1`은 벽, `0`은 빈공간을 의미합니다
    - 플레이어는 바라보고 있는 방향을 설정할 수 있으며, `W`, `E`, `N`, `S`로 설정 가능합니다
    - 맵은 항상 닫힌 공간이어야 하며, 뚫려있을 경우 실행할 수 없습니다


# 조작
- `W` `A` `S` `D`로 움직이고, `up`, `down`, `left`, `right`로 시야를 돌릴 수 있습니다
