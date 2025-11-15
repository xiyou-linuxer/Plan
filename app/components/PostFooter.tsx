"use client";

import { useConfig } from "nextra-theme-docs";

import GhBadge from "./GhBadge";
import Logo from "./Logo";

export default function PostFooter(props: { filePath: string; title: string }) {
  const { filePath, title } = props;
  const { author, editor } = useConfig().normalizePagesResult.activeMetadata;
  return (
    <footer className="post-footer relative my-6 overflow-clip rounded-lg border border-gray-400/10 bg-gray-400/10 p-4">
      <p className="flex flex-wrap items-center gap-x-2 gap-y-1">
        <strong>{title}</strong>
        <a
          className="icon-[ph--pencil-simple-line-bold] text-blue-500"
          href={`https://github.com/xiyou-linuxer/Plan/blame/main/${filePath}`}
          target="_blank"
        />
        {/* {author || editor ? (
          <span className="h-4 border-l-2 border-gray-400" />
        ) : null} */}
        {author?.map?.((name: string) => (
          <GhBadge key={name} name={name} />
        ))}
        {editor?.map?.((name: string) => (
          <GhBadge key={name} name={name} className="opacity-60" />
        ))}
      </p>

      <p>
        文章使用
        <a
          className="mx-1 text-blue-500"
          href="https://creativecommons.org/licenses/by-nc-sa/4.0/deed.zh-hans"
          rel="noopener noreferrer nofollow"
          target="_blank"
        >
          CC BY-NC-SA 4.0
        </a>
        协议。
      </p>

      <Logo className="absolute right-2 bottom-0 -z-1 text-4xl text-gray-400/20 select-none" />
    </footer>
  );
}
