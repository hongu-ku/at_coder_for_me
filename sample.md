### prerequisites

- git

- docker
    - Mac: [Install Docker for Mac](https://www.docker.com/products/docker-desktop)
    - Win: windows proでdocker for windowsを使うか、 https://docs.docker.com/toolbox/toolbox_install_windows/
    - Linux: `[使っているディストリビューション名] docker install 検索`

- docker-sync (**Only for Mac**)
    - Mac: `gem install docker-sync`

- yarn
    - Mac: `brew install yarn`
    - Win: https://yarnpkg.com/ja/docs/install#windows-stable
    - Linux: `[使っているディストリビューション名] yarn install 検索`

### clone this repo

    host$ git clone git@github.com:BEST10developers/travel.ai.git
    host$ cd travel.ai

### start docker-sync (**Only for Mac**)

    host$ docker-sync start

### comment out docker-sync setting (**Only for Win/Linux**)

`docker-compose.yml`
add/comment-out correspoinding lines as follows

```yaml
web:
  volumes:
#    - web-native-osx-sync:/srv/travel.ai:nocopy
    - .:/srv/travel.ai
    - .:/srv/travel.ai:cached

volumes:
# web-native-osx-sync:
#    external: true
```

### start docker container

    host$ docker-compose up -d

### set up docker container (once after docker-copose build)

    host$ docker-compose exec web /bin/zsh -l
    guest$ scripts/setup_docker.sh

### install npm packages and run gulp (on another terminal)

    host$ cd js
    host$ yarn install
    host$ yarn run watch

### start server (on another terminal)

    host$ docker-compose exec web /bin/zsh -l
    guest$ bin/rails s -b 0.0.0.0

Check `http://localhost:3000` from browser on host OS.

Docker container mounts `travel.ai` directory, so you can edit files on host OS!

### cannot connect?

#### 1. check rails process

    guest$ ps aux | grep rails
    docker     480  0.0  6.5 539896 216932 ?       Sl+  01:30   0:13 rails master -e development --pid /srv/travel.ai/tmp/pids/development.pid -b localhost -p 3000
    docker     493  0.0 10.8 925096 358988 ?       Sl+  01:30   0:09 rails worker[0] -e development --pid /srv/travel.ai/tmp/pids/development.pid -b localhost -p 3000

#### 2. check access from docker

    guest$ curl --head localhost:3000

If status is not 200, check `log/unicorn_development.log`

#### 3. check access from host

   host$ curl --head localhost:3000

#### 4. If all succeed but cannot connect from browser, try another browser.

### testing

    # log in to container
    host$ docker-compose exec web /bin/zsh -l

    # run all tests and rubocop
    guest$ bin/rake

    # run specific file
    guest$ bin/rspec spec/features/search_spec.rb

    # run only rubocop
    guest$ bin/rake rubocop

    # run only coffeelint
    guest$ bin/rake my_coffeelint

### Mail check in development environment

Use [mailtrap.io](http://mailtrap.io).

1. Login with github
2. Create new inbox
3. Obtain SMTP HOST and some constants
4. Write variables to `.env` (You need to create .env file yourself in travel.ai/) :
  ```
  DEV_SMTP_USER_NAME = "xxx"
  DEV_SMTP_PASSWORD = "xxx"
  DEV_SMTP_DOMAIN = "xxx" // same value as DEV_SMTP_HOST
  DEV_SMTP_HOST = "xxx"
  DEV_SMTP_PORT = "xxx"
  ```
5. Got mail on mailtrap
- mailtrap is literally trapping mails. You can use every mail address (even if not exists) for signing up on your local AI Travel. If you make `.env` correctly, confirmation mail is sent to the mail box in mailtrap.

http://localhost:8025/ にアクセスすることでも


#### If can not recieve mail in mailtrap
you may do not work `delayed_job`.  
please try this command.

```shell
guest$ bin/rake jobs:work
```

### AWS credential code

Assign it in ENV val: `AWS_ACCESS_KEY_ID="" && AWS_SECRET_ACCESS_KEY="" && AWS_REGION=""`

Trouble Shooting
-------

### docker-sync動いてない

- おかしいコンテナないか確認
    ```
    $ docker ps -a
    CONTAINER ID        IMAGE                 COMMAND                  CREATED             STATUS                        
    PORTS               NAMES
    0d220b7afedb        travelai_web          "scripts/start_serve…"   3 weeks ago         Exited (137) 14 minutes ago                       travelai_web_1
    fbf54d8e1b32        elasticsearch:1.5     "/docker-entrypoint.…"   3 weeks ago         Exited (143) 14 minutes ago                       travelai_elasticsearch_1
    106905921e17        redis:2.8.23          "docker-entrypoint.s…"   3 weeks ago         Exited (0) 14 minutes ago                         travelai_redis_1
    9d6fbce7874f        mysql:5.6.23          "/entrypoint.sh mysq…"   3 weeks ago         Exited (0) 14 minutes ago                         travelai_mysql_1
    9e66f13a8cda        busybox               "sh"                     3 weeks ago         Exited (0) 15 minutes ago                         travelai_datastore_1
    ```
- Exitコードが0じゃないやつ消してみる
    ```
    $ docker rm <container id>
    ```
- cleanしてみる
    ```
    $ docker-sync clean
    ```
- `--foreground` で動かしてログ見てみる
    ```
    $ docker-sync start --foreground
    ```
- syncされるログ出るまで待ってみる（5分以上放置していつの間にかsyncされてたことがある）
