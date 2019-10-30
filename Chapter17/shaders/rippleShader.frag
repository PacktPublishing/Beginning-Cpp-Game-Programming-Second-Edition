// attributes from vertShader.vert
varying vec4 vColor;
varying vec2 vTexCoord;

// uniforms
uniform sampler2D uTexture;
uniform float uTime;

void main() {
	float coef = sin(gl_FragCoord.y * 0.1 + 1 * uTime);
	vTexCoord.y +=  coef * 0.03;
	gl_FragColor = vColor * texture2D(uTexture, vTexCoord);
}
