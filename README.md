# BTDS (Bitcoin Tracking Detecting Solution)

범죄 수사 지원을 목적으로, 비트코인 거래 흐름을 자동으로 추적하고 시각화하는 솔루션

<aside>
💡 BTDS는 수사 기관을 위해 개발된 솔루션으로, 복잡한 비트코인 거래를 그래프 형태로 시각화하여 범죄 수사의 효율성을 높입니다. 이 솔루션은 자동 추적 기능을 통해 거래의 흐름을 빠르게 파악하고 분석할 수 있도록 설계되었습니다.
</aside>

<br/>

## 🛠️ 사용 기술 및 라이브러리

- Typescript, C++
- Next.js, React
- Vis.js, BlockSCI
- bitcoin-core
- MongoDB, Neo4J
- AWS EC2

<br/>

## 🔗 아키텍처

![architecture](https://github.com/dev1ck/bitcoin-tracking-detecting-solution-web/assets/96347313/7c1ca35f-d67b-4469-943a-bce437e27f76)

> Web-Server : [https://github.com/dev1ck/bitcoin-tracking-detecting-solution-web](https://github.com/dev1ck/bitcoin-tracking-detecting-solution-web)
>
> Core-Server : [https://github.com/dev1ck/bitcoin-information-processing-server](https://github.com/dev1ck/bitcoin-information-processing-server)
>
> Documentation-Tool : [https://github.com/dev1ck/bitcoin-wallet-address-documentation](https://github.com/dev1ck/bitcoin-wallet-address-documentation) (사용 중단)

<br/>

## 💡 프로젝트 개요

![슬라이드1](https://github.com/dev1ck/bitcoin-tracking-detecting-solution-web/assets/96347313/1fb57a4a-b4e4-4714-9793-1fc84caf7444)
![슬라이드2](https://github.com/dev1ck/bitcoin-tracking-detecting-solution-web/assets/96347313/e7a6ffa8-dbb3-456f-a76e-2fe1b2d0a95b)
![슬라이드3](https://github.com/dev1ck/bitcoin-tracking-detecting-solution-web/assets/96347313/97184db9-6d74-4260-99ab-572c01b0c885)
![슬라이드4](https://github.com/dev1ck/bitcoin-tracking-detecting-solution-web/assets/96347313/79bcc347-e654-4fae-8561-0948ff2cc9ae)
![슬라이드5](https://github.com/dev1ck/bitcoin-tracking-detecting-solution-web/assets/96347313/0ae11574-a7d3-4efe-857e-204dfd23b60c)
![슬라이드6](https://github.com/dev1ck/bitcoin-tracking-detecting-solution-web/assets/96347313/3775fa9f-5d5d-4ecf-bb5a-b20a0f452313)
![슬라이드7](https://github.com/dev1ck/bitcoin-tracking-detecting-solution-web/assets/96347313/e5426403-5e8a-4696-bb40-52c0a53af2b6)
![슬라이드8](https://github.com/dev1ck/bitcoin-tracking-detecting-solution-web/assets/96347313/148cc057-774b-4255-b641-63966d30df34)

<br/>

## ⚡ 기능 소개

![슬라이드9](https://github.com/dev1ck/bitcoin-tracking-detecting-solution-web/assets/96347313/58474fc7-6fef-428e-8db1-123a48e9f1b5)
![슬라이드10](https://github.com/dev1ck/bitcoin-tracking-detecting-solution-web/assets/96347313/87fe50eb-2ace-49d4-8508-a7acbb6edc44)
![슬라이드11](https://github.com/dev1ck/bitcoin-tracking-detecting-solution-web/assets/96347313/617fbe7e-c359-41e9-ae31-0721d8535e06)
![슬라이드12](https://github.com/dev1ck/bitcoin-tracking-detecting-solution-web/assets/96347313/b24cffb3-0219-4ceb-bd9f-14f699e23a0e)

<br/>

## ⚙️ 자동 추적 동작 원리

![슬라이드13](https://github.com/dev1ck/bitcoin-tracking-detecting-solution-web/assets/96347313/542a1bcd-f97b-4ec7-aed5-1bef946ade4e)

<br/>

---

<br/>

# bitcoin-information-processing-server

## Getting Started

### Prerequisite installer

Install mongocxx, blocksci, cpprestsdk, nlohmann/json

> https://mongocxx.org/mongocxx-v3/installation/linux
>
> https://github.com/citp/BlockSci
>
> https://github.com/microsoft/cpprestdk
>
> https://github.com/nlohmann/json

### Setting Environment

```bash
export MONGO_URI=mongodb://username:password@localhost:27017
export BLOCKSCI_SETTING=BlockSCI-setting-file-location
export SERVER_URL=http://0.0.0.0:port # local 접속만 허용 시 127.0.0.1
```

### Compile and start

```Bash
> make
> ./core-server
```
