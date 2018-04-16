# Kidsnow
Windows/Mac/Android platform에서 사용할 수 있는 OpenGL framework.  

Application class, Input class는 platform independent하게 만들어 두고  
Window class에서 platform dependent한 부분을 모두 해결한다.  

추후에는 Renderer의 인터페이스도 backend independent하게 만들어서 OpenGL 뿐만 아니라 Vulkan 등 다양한 rendering API를 통해 구현할 예정.
