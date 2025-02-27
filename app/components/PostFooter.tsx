'use client'

import { useConfig } from 'nextra-theme-docs'
import GhBadge from './GhBadge'

export default function PostFooter(props: { filePath: string, title: string }) {
  const { filePath, title } = props
  const { author, editor } = useConfig().normalizePagesResult.activeMetadata
  return (
    <footer className="post-footer relative p-6 my-6 bg-gray-400/10 border border-gray-400/10 rounded-lg">
      <span className='title absolute top-0 left-0 text-3xl font-bold text-gray-400/20 pointer-events-none'>{title}</span>

      <p>文章使用 <a className='text-blue-500' href="https://creativecommons.org/licenses/by-nc-sa/4.0/deed.zh-hans" rel="noopener noreferrer nofollow" target="_blank">CC BY-NC-SA 4.0</a> 协议。
        <a href={`https://github.com/xiyou-linuxer/Plan/blame/main/${filePath}`} className="text-blue-500 float-end"><i className="icon-[ph--pencil-simple-line-bold]" /></a>
      </p>



      <div className='flex gap-2 my-1'>
        {author?.map((name: string) => <GhBadge key={name} name={name} />)}
        {editor?.map((name: string) => <GhBadge key={name} name={name} className="opacity-60" />)}
      </div>

      <span className="type-song absolute bottom-0 right-0 text-4xl text-gray-400/20 pointer-events-none">培养计划</span>
    </footer>
  )
}
