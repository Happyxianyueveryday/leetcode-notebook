
# quicksnap-web
基于flask的简易微博web应用

## 1. 构建和运行
  ### Step 1：安装本项目所依赖的库：
  本项目主要基于flask实现后端，使用HTML和扩展UI库bootstrap实现前端。项目本身的运行和部署需要使用下面的第三方库。
  
  ```
  $ pip install flask
  $ pip install flask-login
  $ pip install flask-openid
  $ pip install flask-sqlalchemy
  $ pip install sqlalchemy-migrate
  $ pip install flask-wtf
  $ pip install flask-babel
  $ pip install guess_language
  $ pip install flipflop
  $ pip install coverage
  ```
  
  ### Step 2：下载本项目文件
  点击本页面右上角的"Clone or Download" 按钮，下载本项目，也可以按照个人喜好使用git工具进行clone到本地。
  
  ### Step 3：在项目下载的路径下直接运行
  在下载的本项目的本地路径下运行run.py脚本。
  
  ```
  $ python run.py
  ```
  
  ### Step 4: 启动任意浏览器访问本机
  启动浏览器，地址栏输入"http://localhost:5000" 并访问，即完成本web版微博的运行，如下图所示。
  ![avatar](https://github.com/Happyxianyueveryday/Computer-Vision-demo/blob/master/Demo_2/pics/QQ%E6%88%AA%E5%9B%BE20190410204225.png)
  
  
  ## 2. 基本功能
  本项目较为全面地实现了基本的微博功能，包括：
  
  + 用户账户注册，登录，登出
  + 编辑和发送微博
  + 基于whoosh的文档全局搜索
  + 关注，取消关注用户
  + 生成关注用户的微博动态
  
  本项目同样含有部分的功能尚待完成，即首页的推荐功能，该功能目前不可用，目前计划在下一个版本中结合个人在实验室的另一个项目——基于同态加密的分布式协同过滤系统进行更新。
  
 
  ## 3. 项目结构
  本项目的项目结构如下所示，需要注意的是，此处只展示了重要的源代码部分。
  
  ```
  / -- |-- db_create.py: 数据库新建脚本
       |-- db_migrate.py: 数据库迁移脚本（使用方法：先迁移后更新）
       |-- db_update.py: 数据库更新脚本（使用方法：先迁移后更新）
       |-- config.py: 项目配置文件
       |-- run.py: 可执行脚本文件，直接执行该文件即可运行本项目
       |-- app --|
                 |-- templates: 包含flask的模板(templates)文件
                 |-- __init__.py: 初始化文件
                 |-- forms.py: flask表单文件
                 |-- models.py: flask模型文件
                 |-- view.py: flask视图层文件
  ```
  
  
  ## 4. flask基本设计思想
  
  ### A. ORM的基本思想
  ORM全称是：Object Relational Mapping(对象关系映射)，其概念是是将关系型数据库中的表和面向对象程序设计中的对象联系起来，具体而言：
  
  > ORM将关系型数据库中的一个表和面向对象程序中的一个类对应，将表中的一个属性和类中的一个成员变量对应。
  
  例如下面的sql代码和python代码等价。
  
  ```
  create table Post       
  (
    id integer,     
    body varchar(160),  
    time timestamp,      
    user_id integer,
    
    create view function 
    (
      ...
    )
  );
  ```
  
  ```
  class Post(db.Model):
    id = db.Column(db.Integer, primary_key = True)                              
    body = db.Column(db.String(160))                                            
    time = db.Column(db.DateTime, index=True)
    user_id = db.Column(db.Integer, db.ForeignKey('user.id'))                   
    
    def function(self):
      pass
    
  ```
  
  ### B. MVC设计模式
  MVC是一种经典的web应用软件开发和组织思想。
  
  ![avatar](https://github.com/Happyxianyueveryday/Computer-Vision-demo/blob/master/Demo_2/pics/MVC.png)
  
  MVC中的V代表View，即视图层；C代表Controller，即控制器；M代表Model，即模型，是底层的数据库。三部分组件的基本功能如下。  
  (1) 视图(View)：是指用户看到并与之交互的html界面，视图只负责如何显示从控制器得到的结果数据。    
  (2) 控制器(Controller)：控制器接受用户的输入并调用模型中的视图去完成用户的需求，控制器本身不输出任何东西和做任何处理。它只是接收请求并决定调用哪个模型构件去处理请求，然后再确定用哪个视图来显示返回的数据。  
  (3) 模型(Model)：模型表示业务规则，底层和数据库直接相连。在MVC的三个部件中，模型拥有最多的处理任务。被模型返回的数据是中立的，模型与数据格式无关，这样一个模型能为多个视图提供数据，由于应用于模型的代码只需写一次就可以被多个视图重用，所以减少了代码的重复性。  
  
  ### C. flask的变形版MVC——MTV设计模式
  具体到flask后端框架，它使用的设计模式是MTV，这是一种变形版的MVC。
  
   ![avatar](https://github.com/Happyxianyueveryday/Computer-Vision-demo/blob/master/Demo_2/pics/MTV.png)
   
  MTV中的M代表模型(Models)，对应于这个项目中的'/app/model.py'文件；T代表模板(Templates)，对应于这个项目中的'app/templates/'文件夹；V代表视图(Views)，对应于这个项目中的'app/views.py'文件。另外还有一个额外的部件为控制器(Controller)，四个部分的具体功能如下所示。  
  (1) 模型(Models)：flask中的模型使用sqlachemey和底层数据库相联系，负责从视图接受操作指令，然后根据指令进行数据库的增删改查。  
  (2) 模板(Templates)：flask中的模板负责从视图接受数据，并通过jinja2引擎渲染出用户页面呈现给用户。  
  (3) 视图(Views)：flask中的视图负责收到用户的请求后，拥有最多的处理任务，需要对请求的合法性进行检查，然后从向模型发出操作指令。  
  (4) 控制器(Controller)： flask中的控制器仅负责进行路由，不做任何的逻辑处理，将一个url映射到一个视图函数上。

  
  具体到本项目，我们以删除一条已经发送的微博来展示整个flask架构的MTV设计模式是如何工作的，我们假设web应用仅在本机上运行，端口号为5000 (localhost:5000)：  
  (1) 用户点击删除微博的按钮，发送一个url：'localhost:5000/delweibo/id=1'，这里的'/delweibo'指明了要删除功能，'/id=1'指定了要删除的微博的id     
  (2) 控制器(Controller)的工作：根据用户点击时发送的url，匹配到视图view.py中的一个视图函数delweibo，将要删除的id作为参数传递给视图函数delweibo  
  (3) 视图(View)的工作：视图部分做最多的处理工作，在视图中的视图函数delweibo被调用后，需要首先检查删除操作的合法性（用户需要登录，用户仅能删除自己的微博），若删除操作合法，则向模型发送指令，指示模型删除微博，并将删除成功的提示信息交付给模板'app/templates/base_navigation_bar.html'进行显示     
  (4) 模型(Model)的工作：flask中的模型就是sqlalchemy，sqlalchemy收到来自视图的删除指令后，联系底层数据库删除id为1的微博记录      
  (5) 模板(Templates)的工作：模板文件'app/templates/base_navigation_bar.html'负责显示视图层反馈的提示信息     
 
  
  ## 5. 安全性策略
  
  本项目中的安全性主要分为三个部分：密码安全性，url安全性，表单安全性。
  
  ### A. 密码安全性
  考虑到密码可能泄露的问题，用户的密码不应当直接储存在服务器上，而是需要使用Hash函数，利用Hash函数极低碰撞概率和不可还原的特性，仅将服务器的密码的hash值储存在服务器，而在用户登录需要验证密码的时候，先在本地计算密码的hash值，然后将hash值发送给服务器，在服务器中将用户输入的密码的hash值和服务器存储的正确密码的hash值进行比对来判断正确性。
  
  ### B. url安全性
  url是用户发起请求的重要手段，一个web应用应该足够安全能够抵抗非法url请求。例如用户试图在没有登录的情况下访问自己的主页，一个已经登录的用户视图使用url删除其他用户的微博等。对于上述问题，我们使用如下的两种手段进行安全性控制。
  
  + 1. 登录控制：用户试图通过url访问一些敏感功能时，需要首先要求用户进行登录，在flask中有以下的三种实现方式。
  
  ```
  if current_user.is_authenticated:
    flash('已经进行登录')
  else:
    flash('尚未进行登录')
  ```
  
  ```
  @login_required
  ```
  
  + 2. url逻辑控制：在每一个url对应的视图函数中，应该严格检查用户所发起的请求的逻辑是否合法，例如：删除操作的合法性（用户首先需要登录，用户仅能删除已经存在的且是自己发送的微博。）
  
  ### C. 表单安全性
  flask中通过wtform保证表单安全性，防止用户在提交的表单中注入非法字段数据。
  
  
  
  
  
  
