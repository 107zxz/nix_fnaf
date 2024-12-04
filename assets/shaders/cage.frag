#version 330

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;

// Input uniform values
uniform sampler2D texture0;
uniform vec4 colDiffuse;

// Output fragment color
out vec4 finalColor;

// NOTE: Add here your custom variables
uniform sampler2D texture1;
uniform float time;
uniform vec4 tint;

const float SHAKE_INTENSITY = 0.007;
// const float SHAKE_INTENSITY = 0.000;

void main()
{
    // Texel color fetching from texture sampler

    vec2 texCoord = fragTexCoord + vec2(sin(time * 5), cos(time * 5)) * SHAKE_INTENSITY;

    if (texCoord.y > 1) {texCoord.y *= -1;}

    vec4 texelColor = texture(texture1, texCoord);

    // NOTE: Implement here your fragment shader code
    

    // final color is the color from the texture 
    //    times the tint color (colDiffuse)
    //    times the fragment color (interpolated vertex color)
    finalColor = texelColor * tint;
}
