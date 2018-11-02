#
#  Be sure to run `pod spec lint JXRSDahuaSDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|
  s.name         = "JXRSDahuaSDK"
  s.version      = "1.0.0"
  s.summary      = "A short description of JXRSDahuaSDK."
  s.description  = <<-DESC
            大华sdkpod
                      DESC

  s.homepage     = "http://EXAMPLE/JXRSDahuaSDK"
  s.license      = "MIT"
  s.author             = { "tao cheng" => "" }
  s.platform     = :ios, "5.0"

  s.source       = { :git => "https://github.com/qingtianct/DaHuaSDK.git", :tag => "#{s.version}" }
#s.source_files  = "ios_ibp_sdk/include", "ios_ibp_sdk/include/**/*.{h}"

  s.exclude_files = "Classes/Exclude"

  s.public_header_files = "ios_ibp_sdk/include/*.h"

  # s.resource  = "icon.png"
  # s.resources = "Resources/*.png"
  # s.preserve_paths = "FilesToSave", "MoreFilesToSave"

  s.frameworks = "AudioToolbox", "AVFoundation"
  s.library = "stdc++"
  s.vendored_libraries = "ios_ibp_sdk/**/**/*.{a}"

  s.requires_arc = true
  # s.xcconfig = { "HEADER_SEARCH_PATHS" => "$(SDKROOT)/usr/include/libxml2" }
  # s.dependency "JSONKit", "~> 1.4"

end
