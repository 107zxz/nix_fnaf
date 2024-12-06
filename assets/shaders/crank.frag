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

const float SHAKE_INTENSITY = -0.007 * 3;
// const float SHAKE_INTENSITY = 0.000;

void main()
{
    // Texel color fetching from texture sampler

    vec2 texCoord = fragTexCoord;

    // Rotate crank
    float s = sin(time * -10);
    float c = cos(time * -10);

    texCoord -= vec2(0.15, 0.75);

    texCoord *= mat2(c, -s, s, c);

    // texCoord = vec2(0.5 * c - 0.5 * s, 0.5 * s + 0.5 * c);
    texCoord *= 5;
    texCoord += vec2(0.5, 0.5);

    texCoord += vec2(sin(time * 5), cos(time * 5)) * SHAKE_INTENSITY;

    vec4 texelColor = texture(texture1, texCoord);

    if (!(
        texCoord.x < 1
        && texCoord.x > 0
        && texCoord.y > 0
        && texCoord.y < 1
    )) texelColor.a = 0;

    // texCoord *= vec2(8, 3);
    // texCoord += vec2(0.25, 0);

    // // NOTE: Implement here your fragment shader code
    // texCoord += vec2(0, raisestate);


    // final color is the color from the texture 
    //    times the tint color (colDiffuse)
    //    times the fragment color (interpolated vertex color)
    finalColor = texelColor * tint;
}
