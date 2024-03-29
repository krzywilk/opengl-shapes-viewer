# Introduction
Learning OpenGL by implementing an SDK for basic shape generation and lighting manipulation.

Code is based on [learn OpenGl tutorial](https://learnopengl.com/). 

Currently implemented chapters:
- [Getting started](https://learnopengl.com/Getting-started/OpenGL)
- [Lighting](https://learnopengl.com/Lighting/Colors)
- [Model Loading](https://learnopengl.com/Model-Loading/Assimp) (in progress...)


# Build process
The building process is being implemented. The implementation is to be based on a [repository with an example](https://github.com/tgalaj/OpenGLSampleCmake).

The manual process of setting up the IDE is described in the [above-mentioned tutorial](https://learnopengl.com/Getting-started/Creating-a-window)

<details>
 <summary>Build scritp</summary>

	mkdir build
	cd build
	cmake -A x64 ..
</details>

# Run
The [runner file](https://github.com/krzywilk/open-gl-shapes-viewer/blob/master/Runner.cpp) contains an example of the use of the implemented functionalities.
<p align="center">
  <img src="static_files/readme_resources/introduction_boxes.gif" alt="introduction_boxes" />
</p>
