字节码是一种源码编译后的中间显示，与汇编有类似之处，但是运行于特定的语言虚拟机中，因此它其中包含的指令不是及其指令，而是平台无关的，由虚拟机实现的虚拟机指令。
字节码是一种运行于某种虚拟机中的，更抽象的汇编。

字节码的保护：
    字节码经历了完整的编译流程，抹除了源码中携带的额外语义信息，其逆向难度可以于传统的编译型语言相比。
    代码混淆仅仅是障眼法，也无法防止篡改着在混淆后的源码中加入探针和钩子代码。


V8的字节码处理：
    1. 在V8 的运行过程中，代码会被编译为字节码。
    2. 字节码不是一个暴露在外的功能，其格式未标准化,与V8的版本紧密相关。
    3. 如果直接把字节码喂给V8，可以略过Parser和AST，获取一定的性能提示。