#version 110

//varying "out" variables to be used in the fragment shader
varying vec4 vColor;
varying vec2 vTexCoord;
 
void main() {
    vColor = gl_Color;
    vTexCoord = (gl_TextureMatrix[0] * gl_MultiTexCoord0).xy;
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}

