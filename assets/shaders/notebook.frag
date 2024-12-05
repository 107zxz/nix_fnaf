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
uniform float raisestate;
uniform vec4 tint;

const float SHAKE_INTENSITY = 0.007;
// const float SHAKE_INTENSITY = 0.000;

void main()
{
    // Texel color fetching from texture sampler

    vec2 texCoord = fragTexCoord;
    texCoord *= vec2(3, 2);
    texCoord += vec2(0, -0.7);
    texCoord += vec2(sin(time * 5), cos(time * 5)) * SHAKE_INTENSITY;

    // NOTE: Implement here your fragment shader code
    texCoord += vec2(0, raisestate);
    vec4 texelColor = texture(texture1, texCoord);

    if (!(
        texCoord.x < 2
        && texCoord.x > 1
        && texCoord.y > 1
        && texCoord.y < 2
    )) texelColor.a = 0;

    // final color is the color from the texture 
    //    times the tint color (colDiffuse)
    //    times the fragment color (interpolated vertex color)
    finalColor = texelColor * tint;
}
