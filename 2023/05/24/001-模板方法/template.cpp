/**
 * 调用关系：application调用library设计的步骤
 */

// file: library
class Library {
   public:
    void step1();
    void step3();
    void step5();
};

// file: aplication
class Application {
   public:
    bool step2();
    void step4();
};

// file: main.cpp
int main() {
    Library lib;
    Application app;
    lib.step1();
    while (app.step2()) {
        lib.step3();
    }
    app.step4();
    lib.step5();
}

/**
 * 使用模板方法，定义一个算法的框架，将一些步骤延迟到子类实现。在子类中可以复用算法的框架，同时改变一些关键的步骤
 */
class Library {
   public:
    void step1();
    void step3();
    void step5();
    virtual bool step2();
    virtual void step4();
    virtual ~Library();

    void run() {
        step1();
        while (step2()) {
            step3();
        }
        step4();
        step5();
    }
};

// file: aplication
class Application : public Library {
   public:
    bool step2();
    void step4();
};

// file: main.cpp
int main() {
    Library* app = new Application;
    app->run();
}