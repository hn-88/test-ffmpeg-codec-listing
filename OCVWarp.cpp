extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/avutil.h>
}

#include <iostream>

void listSupportedCodecs() {
    // Initialize FFMPEG
    // avcodec_register_all(); // deprecated since ffmpeg v4 in 2018

    std::cout << "Supported Codecs:" << std::endl;

    // Iterate through all registered codecs
    const AVCodec* codec = nullptr;
    void* iterator = nullptr;

    while ((codec = av_codec_iterate(&iterator))) {
        std::string codecType;

        // Determine the codec type
        if (codec->type == AVMEDIA_TYPE_VIDEO) {
            codecType = "Video";
        } else if (codec->type == AVMEDIA_TYPE_AUDIO) {
            codecType = "Audio";
        } else {
            codecType = "Other";
        }

        // Print codec information
        std::cout << "- " << codec->name
                  << " (" << codec->long_name << ")"
                  << " [Type: " << codecType << "]"
                  << (av_codec_is_encoder(codec) ? " [Encoder]" : "")
                  << (av_codec_is_decoder(codec) ? " [Decoder]" : "")
                  << std::endl;
    }
}

int main() {
    // List all supported codecs
    listSupportedCodecs();
    return 0;
}
